package cp_java;

import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.lang.reflect.Method;

import com.google.gson.Gson;
import com.google.gson.TypeAdapter;
import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonToken;
import com.google.gson.stream.JsonWriter;

class Main {
    public static void main(String[] args) throws Throwable {
        var testsetFile = args[0];
        List<Object[]> inputList = new ArrayList<>();
        List<Object> answerList = new ArrayList<>();

        if(testsetFile != null) {
            readTestcaseFile(testsetFile, inputList, answerList, false);
        } else {
            // TODO: Allow input from STDIN on each test iteration
        }

        var solutionCls = Class.forName("Solution");
        var ctor = solutionCls.getDeclaredConstructor();
        ctor.setAccessible(true);
        Object solutionInstance = ctor.newInstance();
        Method solutionMethod = Arrays.stream(solutionCls.getDeclaredMethods())
            .filter(x -> x.getName().equals("solution"))
            .findFirst().get();
        solutionMethod.setAccessible(true);

        var plainGson = new Gson();
        for(int i=0; i<inputList.size(); ++i) {
            Object[] inputEntry = inputList.get(i);

            Object returnVal = solutionMethod.invoke(solutionInstance, inputEntry);

            System.out.println(String.format("[    Your answer] %s", plainGson.toJson(returnVal)));
            if(answerList.get(i) == null) continue;
            
            System.out.println(String.format("[Expected answer] %s", plainGson.toJson(answerList.get(i))));
        }

    }

    static void readTestcaseFile(String path, List<Object[]> inputList, List<Object> answerList, boolean isAnswerless) throws IOException {

        var parser = new SaneAdapter();

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            List<Object> inputEntry = new ArrayList<>();
            while(true) {
                String line = br.readLine();

                if(line == null || line.length() == 0) {
                    if(inputEntry.size() < 2) {
                        throw new IOException("Wrong testcase format: inputEntry.size() < 2");
                    }

                    if(!isAnswerless) {
                        Object answerEntry = inputEntry.remove(inputEntry.size() - 1);
                        answerList.add(answerEntry);
                    }

                    inputList.add(inputEntry.toArray());
                    inputEntry.clear();
                    
                    if(line == null) break;
                    else continue;
                }

                inputEntry.add(parser.fromJson(line));
            }
        }
    }

    // https://stackoverflow.com/questions/44270723/how-to-deserialize-array-of-unknown-dimension-with-gson
    static class SaneAdapter extends TypeAdapter<Object> {

        @Override
        public void write(JsonWriter out, Object value) throws IOException {
            /*
            if(value.getClass().isArray()) {
                out.beginArray();
                int length = Array.getLength(value);
                for(int i=0; i<length; ++i) {
                    Object arrayElem = Array.get(value, i);
                    write(out, arrayElem);
                }
                out.endArray();
            } else {
                out.value((String)value);
            }
            */
        }

        @Override
        public Object read(JsonReader in) throws IOException {
            // TODO: Hetero array
            // TODO: JSON Object
            if(in.peek() == JsonToken.BEGIN_ARRAY) {
                ArrayList<Object> elements = new ArrayList<>();
                in.beginArray();
                do {
                    elements.add(read(in));
                } while(in.peek() != JsonToken.END_ARRAY);
                in.endArray();

                if(elements.size() == 0) {
                    throw new IOException("Cannot determine type for empty array");
                }
                else {

                    Class<?> cls = elements.get(0).getClass();
                    if(cls.isArray()) {
                        Object ans = Array.newInstance(cls, elements.size());
                        for(int i=0; i<elements.size(); ++i) {
                            Array.set(ans, i, elements.get(i));
                        }
                        return ans;
                    } else if (cls == String.class) {
                        String[] ans = new String[elements.size()];
                        for(int i=0; i<elements.size(); ++i) {
                            ans[i] = (String) elements.get(i);
                        }
                        return ans;
                    } else if(cls == Integer.class) {
                        int[] ans = new int[elements.size()];
                        for(int i=0; i<elements.size(); ++i) {
                            ans[i] = (int) elements.get(i);
                        }
                        return ans;
                    } else if(cls == Double.class) {
                        double[] ans = new double[elements.size()];
                        for(int i=0; i<elements.size(); ++i) {
                            ans[i] = (double) elements.get(i);
                        }
                        return ans;
                    } else if(cls == Boolean.class) {
                        boolean[] ans = new boolean[elements.size()];
                        for(int i=0; i<elements.size(); ++i) {
                            ans[i] = (boolean) elements.get(i);
                        }
                        return ans;
                    } else {
                        throw new IOException("Unsupported Type " + cls.getName());
                    }
                }
            } else if (in.peek() == JsonToken.STRING) {
                return in.nextString();
            } else if (in.peek() == JsonToken.NUMBER) {
                var tmp = in.nextString();
                if(tmp.indexOf('.') == -1 && tmp.indexOf('e') == -1 && tmp.indexOf('E') ==- 1) {
                    return Integer.parseInt(tmp);
                } else {
                    return Double.parseDouble(tmp);
                }
            } else if (in.peek() == JsonToken.BOOLEAN) {
                return in.nextBoolean();
            } else {
                throw new IOException("Unsupported Token: " + in.peek().name());
            }
        }

    }
}

#!/usr/bin/env bash

helpmsg='Usage: . init.sh <type>)'
if ! (return 0 2>/dev/null); then
  >&2 echo $helpmsg
  return 1
fi
if [ ! "$1" ]; then
  >&2 echo $helpmsg
  return 1
fi
unset helpmsg


case $1 in
  pr|programmers|lc|leetcode|json) RUNTYPE=json;;
  boj|cf|codeforces|plain) RUNTYPE=plain;;
esac

echo '# lang=<LANGUAGE ID>'
echo '# sol=<PATH TO SOLUTION FILE>'
echo '# ts=<PATH TO TESTSET FILE>'


CPROOT="$(builtin cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && builtin pwd )"
myvi=nvim

gen() {
  if [ $RUNTYPE == "json" ]; then
    setup_vars
    if ! [ -e "$abs_sol" ]; then
      cp "$CPROOT/runner/$lang/template/tpl.$lang" "$abs_sol";
    fi
  fi
}

e() {
  setup_vars && \
    $myvi `realpath -m --relative-to=. "$abs_sol"`
}
g() {
  setup_vars && \
    [ -e "$abs_sol" ]
    (builtin cd "$CPROOT/runner/$lang" && TYPE=$RUNTYPE exec ./run.sh $abs_sol $abs_ts)
}

setup_vars() {
  if [ ! $lang ]; then
    echo "'lang' unset" >&2
    return 1
  fi

  if [ ! $sol ]; then
    echo "'sol' is unset" >&2
    return 1
  fi

  local ssol="${sol%*.$lang}.$lang"
  abs_sol=`realpath -m $ssol`

  if ! [ $ts ]; then
    abs_ts=
  else
    if ! [ -f "$ts" ]; then
      echo "file '$ts' not found" >&2
      return 1
    fi

    abs_ts=`realpath -e $ts`
  fi

}

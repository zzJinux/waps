def solution(table, languages, preference):
    lutbl = {}
    for record in table:
        tp, *langs = record.split()
        lutbl[tp] = {lang: 5-i for i, lang in enumerate(langs)}

    mxsum = 0
    anstp = ''
    for tp, dictv in lutbl.items():
        Z = len(languages)
        summ = 0
        for i in range(Z):
            summ += dictv.get(languages[i], 0) * preference[i]

        if mxsum < summ:
            mxsum = summ
            anstp = tp
        elif mxsum == summ and anstp > tp:
            anstp = tp
    return anstp

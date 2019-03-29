import sys
in_file = open('1.inp', 'r')
f = open('1_out.out', 'w')
isNumber = 0
for line in in_file:
    isNumber += 1
    #문자를 숫자로
    if isNumber == 1:
        N = int(line)
        continue;   #숫자이면 데이터에 추가하지 않는다
    data = list(line.strip())
    #한 데이터의 끝까지 돌려보기
    if len(data) % 2 == 0:
        mid = len(data)
    elif len(data) % 2 == 1:
        mid = len(data)-1
    result = 0
    tmp = ''
    if list(data) == list(reversed(data)):
        result = 1
    else:   #데이터를 뒤집은 것이 다르다면

        for i in range(0, len(data)): #하나씩 돌려보면서
            tmp = data[i]
            data.pop(i) #인덱스를 빼고
            if list(data) == list(reversed(data)):  #뒤집은걸 비교해본다
                result = 2
                break;
            else:
                result = 3
                shortlen = -1
                data.insert(i, tmp)

    f.write(str(result) + "\n")
z
f.close()
in_file.close()
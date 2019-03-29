input = open('./palin.inp', 'r')
output = open('./palin.out', 'w')

count = int(input.readline())

def isPalindrome(str):
    if (not str or len(str) == 0):
        return '3'

    half = int(len(str) / 2)
    isPseudo = False
    i = 0
    j = len(str) - 1

    while (i < half):
        if (str[i] != str[j]):
            if (not isPseudo):
                isPseudo = True
                if (str[i] == str[j - 1]): j -= 1
                elif (str[i + 1] == str[j]): i += 1
                else: return '3'
            else: return '3'
        i += 1
        j -= 1

    if (isPseudo): return '2'
    return '1'

for _ in range(count):
    str = input.readline().rstrip()
    output.write(isPalindrome(str) + '\n')

output.close()
input.close()

#ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
# PALIN = 1
# PSEUDO_PALIN = 2
# NOT_PALIN = 3
#
#
# def reverse(string):
#     return string[::-1]
#
# def is_palin(string):
#     mid = len(string) // 2
#     d = 1 if len(string) % 2 else 0
#     beg_mid = string[:mid]
#     mid_end = string[mid+d:]
#     end_mid = reverse(mid_end)
#     return beg_mid == end_mid
#
# def removed1ch_strseq(string):
#     """ '1234' => '234','134','124','123' """
#     for i in range(len(string)):
#         yield string[:i] + string[i+1:]
#
# def is_pseudo_palin(string):
#     for s in removed1ch_strseq(string):
#         if is_palin(s):
#             return True
#     return False
#
# def kind(string):
#     if is_palin(string):
#         return PALIN
#     elif is_pseudo_palin(string):
#         return PSEUDO_PALIN
#     else:
#         return NOT_PALIN
#
# with open('palin.inp', 'r') as inp, open('palin.out', 'w') as out:
#     _ = str(inp.readline()) # skip useless N
#     strs = inp.readlines()
#     str2ans = lambda s:str(kind(s[:-1]))+'\n' # [:-1] remove '\n'
#     kinds = map(str2ans, strs)
#     out.writelines(kinds)
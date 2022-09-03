class Solution:
    def removeStars(self, s: str) -> str:
        temp_string = ''
        latest_index = -1
        del_count = 0
        for index,value in enumerate(s):
            if value != '*':
                if del_count > 0:
                    del_count -= 1
                    continue
                temp_string += value
                latest_index += 1
                #print(temp_string)
            else:
                if latest_index == -1:
                    del_count += 1
                temp_string = temp_string[:latest_index]
                latest_index -= 1 
                #print("else",temp_string)
        return temp_string
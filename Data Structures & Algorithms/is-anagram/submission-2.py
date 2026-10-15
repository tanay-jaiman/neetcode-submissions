class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_list = [char for char in s]
        s_list.sort()
        t_list = [char for char in t]
        t_list.sort()

        print(s_list)
        print(t_list)

        if s_list == t_list:
            return True
        return False
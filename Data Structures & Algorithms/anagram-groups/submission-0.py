class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_map = {}
        for item in strs:
            if not str_map.get("".join(sorted(item)), None):
                str_map["".join(sorted(item))] = [item]
            else:
                str_map["".join(sorted(item))].append(item)
        return [j for i,j in str_map.items()]
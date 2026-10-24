class Solution:

    def encode(self, strs: List[str]) -> str:
        size, res = [], []
        # Find lengths
        for i in strs:
            size.append(len(i))
        # create the header
        for i in size:
            res.append(str(i)) # append the length
            res.append(",") # append length boundary
        res.append("#") # append len-str boundary
        res.extend(strs) # append all the strs
        res = "".join(res) # join them to make one string which will be header+strs
        return res

    def decode(self, s: str) -> List[str]:

        size,res,i = [], [], 0
        # identify len-str boundary
        while s[i] != "#":
            j=i
            # inside this identify len boundary
            while s[j] != ",": # go till you identify a "," becuase the string can have a length of 12, 120, 1200, so we need to start from 1 and go till 0
                j += 1
            size.append(int(s[i:j]))
            i = j+1 # now start after the ","
        i = i+1 # go after the "#", becasue from there only the str will start

        # slice the strs directly from the sizes identified from the header.
        for sz in size:
            res.append(s[i:i+sz])
            i = i+sz
        return res

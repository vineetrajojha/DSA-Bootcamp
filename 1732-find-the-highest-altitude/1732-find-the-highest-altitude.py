import numpy as np
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        highest= int(max(np.cumsum(gain)))
        if highest>=0:
            return highest
        return 0
            
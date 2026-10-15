class Solution:

    def encode(self, strs: List[str]) -> str:
        if strs == []:
            return (b'\0\0').decode()
        return b'\0'.join([string.encode() for string in strs]).decode()

    def decode(self, s: str) -> List[str]:
        s = s.encode()
        if s == b'\0\0':
            return []
        strs = s.split(b'\0')
        return [string.decode() for string in strs]
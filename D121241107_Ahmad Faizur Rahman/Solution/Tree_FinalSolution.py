# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        ser = []

        def dfs (root):
            if root is None:
                ser.append('null')
                return
            ser.append(str(root.val))
            dfs(root.left)
            dfs(root.right)

        dfs(root)
        return ','.join(ser)

        

    def deserialize(self, data):
        value = data.split(',')
        self.ptr = 0
            
        def dfs():
            if value[self.ptr] == 'null':
                self.ptr += 1
                return None

            node = TreeNode(int(value[self.ptr]))
            self.ptr += 1
            node.left = dfs()
            node.right = dfs()
            return node
            
        return dfs()
        
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
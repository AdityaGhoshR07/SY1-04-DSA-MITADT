class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        new_node = Node(data)

        if self.root is None:
            self.root = new_node
            return

        current = self.root
        while True:
            if data < current.data:
                if current.left is None:
                    current.left = new_node
                    return
                current = current.left
            elif data > current.data:
                if current.right is None:
                    current.right = new_node
                    return
                current = current.right
            else:
                print(f"Duplicate value {data} ignored.")
                return

    def inorder_non_recursive(self):
        stack = []
        current = self.root
        result = []

        while current is not None or stack:
            while current is not None:
                stack.append(current)
                current = current.left

            current = stack.pop()
            result.append(current.data)
            current = current.right

        return result

    def preorder_non_recursive(self):
        if self.root is None:
            return []

        stack = [self.root]
        result = []

        while stack:
            current = stack.pop()
            result.append(current.data)

            # Push right first so that left is processed first.
            if current.right is not None:
                stack.append(current.right)
            if current.left is not None:
                stack.append(current.left)

        return result


def main():
    tree = BinarySearchTree()

    n = int(input("Enter number of nodes: "))
    if n < 0:
        print("Number of nodes cannot be negative.")
        return

    for i in range(n):
        value = int(input(f"Enter value {i + 1}: "))
        tree.insert(value)

    print("\nInorder Traversal (Non-Recursive):")
    print(*tree.inorder_non_recursive())

    print("\nPreorder Traversal (Non-Recursive):")
    print(*tree.preorder_non_recursive())


if __name__ == "__main__":
    main()
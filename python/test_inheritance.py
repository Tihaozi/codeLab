class SquareSumComputer(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def transform(self, x):
        return x * x

    def inputs(self):
        return range(self.a, self.b)

    def compute(self):
        return sum(self.transform(value) for value in self.inputs())


class CubeSumComputer(SquareSumComputer):
    def transform(self, x):
        return x * x * x


if __name__ == "__main__":
    cube = CubeSumComputer(2, 5)
    print cube.compute()

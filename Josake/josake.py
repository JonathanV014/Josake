from Josake.c_module import my_c_extension


class NumericalAnalysis:
    def __init__(self):
        pass

    def hello_world(self):
        return my_c_extension.hello_world() 

from Josake.c_module import norms_and_errors
class Norm:
    """
    Class to calculate norms
    
    Parameters
    ----------
    None

        
    """
    # def __init__(self):
    #     pass
    
    def one(self, data) -> float:
        if self.data_type(data) == 'v':
            return norms_and_errors.norm_one_vector(data)
        elif self.data_type(data) == 'm':
            pass #c matriz method
        else:
            pass #No calulate
        pass

    def euclidean(self, data) -> float:
        if self.data_type(data) == 'v':
            pass #c vector metod
        elif self.data_type(data) == 'm':
            pass #No calculate
        else:
            pass #No calculate
        pass

    def infinite(self, data) -> float:
        if self.data_type(data) == 'v':
            pass #c vector method
        elif self.data_type(data) == 'm':
            pass #c matriz method
        else:
            pass #No calulate
        pass

    def frobenius(self, data) -> float:
        if self.data_type(data) == 'v':
            pass #No calulate
        elif self.data_type(data) == 'm':
            pass #c matriz method
        else:
            pass #No calulate
        pass


    def data_type(self, data) -> str:
        d_type = "n"
        if type(data == list):
            d_type = "v"
            if type(data[0]) == list:
                d_type = "m"
        return d_type

class Error:
    def __init__(self):
        pass

from munkres import Munkres,print_matrix
import sys

def munkres_test():
    m=Munkres()
    #matrix=[[5,9,1],[10,3,2],[8,7,4]]
    matrix=[[16,22,17,17],[14,23,15,16],[18,21,17,17],[19,24,21,22],[17,22,19,20]]
    cost_matrix = []
    for row in matrix:
        cost_row = []
        for col in row:
                cost_row += [sys.maxsize - col]
        cost_matrix += [cost_row]
    indexes=m.compute(cost_matrix)
    print_matrix(matrix, msg='Lowest cost through this matrix:')
    total = 0
    for row, column in indexes:
            value = matrix[row][column]
            total += value
            print '(%d, %d) -> %d' % (row, column, value)
    print 'total cost: %d' % total


if __name__ == '__main__':
    munkres_test()

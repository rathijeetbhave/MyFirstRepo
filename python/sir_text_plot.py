import sys

class PlotException(Exception):
    pass

def make_canvas(size):
    cols, rows = size
    canvas = []
    for i in range(cols):
        canvas.append(list(' '*rows))
    return canvas

def plot_canvas(canvas, output_file):
    for line in canvas[::-1]:
        output_file.write(''.join(line))
        output_file.write('\n')

def map_point(x, y, xmin, ymin, xmax, ymax, size):
    """Return a pair of indices corresponding to
    the point x, y in the domain (xmin,...)
    """
    len_x = float(xmax - xmin)
    len_y = float(ymax - ymin)
    xi = int(round((x - xmin)/len_x*(size[1]-1)))
    yi = int(round((y - ymin)/len_y*(size[0]-1)))
    return xi, yi

def plot(x_a, y_a, size=(80, 30), output_file=sys.stdout):
    if len(x_a) != len(y_a):
        msg = "Input arrays have different lengths %d and %d"%(len(x_a), len(y_a))
        raise PlotException(msg)
    xmin, xmax = min(x_a), max(x_a)
    ymin, ymax = min(y_a), max(y_a)

    canvas = make_canvas(size)

    n = len(x_a)
    for i in range(n):
        x, y = x_a[i], y_a[i]
        xi, yi = map_point(x, y, xmin, ymin, xmax, ymax, size)
        canvas[yi][xi] = '*'

    plot_canvas(canvas, output_file)

def test_make_canvas():
    size = (6, 5)
    canvas = make_canvas(size)
    assert len(canvas) == size[1]
    assert len(canvas[0]) == size[0]
    for i in range(size[1]):
        for j in range(size[0]):
            assert canvas[i][j] == ' '

def test_map_point():
    pass

def test_plot():
    x = [0, 1]
    y = [0, 1]
    plot(x, y, size=(10,10))


def main():
    import numpy as np
    x = np.linspace(0, 2*np.pi, 40)
    plot(x, np.sin(x), size=(20, 60))

if __name__ == '__main__':
    main()

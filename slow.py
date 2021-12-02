

def slowsort(array, i, j, drawData):
    if i >= j:
        return
 
    m = int((i + j) / 2)
    slowsort(array, i, m, drawData)
    slowsort(array, m + 1, j, drawData)
    if array[j] < array[m]:
        k = array[m]
        array[m] = array[j]
        array[j] = k
        drawData(array, '#F50BED')
 
    slowsort(array, i, j - 1, drawData)
    

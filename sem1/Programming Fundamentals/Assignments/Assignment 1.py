from texttable import Texttable

def createBoard():
    return [0]*9

def tostring(board)->str:
    table=Texttable()
    table.set_cols_align(["c","c","c"])

    formattedTable =[]
    for i in range(3):
        row=[]
        for j in range(3):
            cell=board[3*i+j]
            if cell==-1:
                row.append('0')
            elif cell==1:
                row.append('X')
            else:
                row.append(' ')
        formattedTable.append(row)
    table.add_rows(formattedTable,header=False)
    return table.draw()

def main():
    board=createBoard()
    print(tostring(board))
main()
open Day3DataInterpreter;

type point = Unclaimed | Claimed | MultiClaimed

let getColumnNumbers = (rect: claim): list(int) => {
    let firstCol = rect.colStart;
    let rec buildColumns = (columns: list(int)) => {
        switch (List.hd(columns)) {
            | column when column == firstColumn => columns;
            | column => buildColumns([column - 1, ...columns]);
        }
    }

    buildColumns([rect.colStart + rect.width - 1]);
}

let getFirstRowPoints = (rect: claim): list((int, int)) => {
    getColumnNumbers(rect)
    |> List.map((colNumber => (colNumber, rect.rowStart)))
}

let buildColumnPointsFromTop = (rect: claim, firstPoint: (int, int)): list((int,int)) => {
    let (column, firstRow) = firstPoint;
    let rec buildRows = (rows: list((int, int))) => {
        switch (List.hd(rows)) {
            | (_, row) when row == firstRow => rows;
            | (_, otherRow) => buildRows([(column, otherRow - 1), ...rows]);
        }
    }
    buildRows([(column, firstRow + rect.height - 1)]);
}

let buildPointsList = (rect: claim): list((int, int)) => {
    getFirstRowPoints(rect)
    |> List.map(buildColumnPointsFromTop(rect))
    |> List.flatten
}
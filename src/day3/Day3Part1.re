open Day3DataInterpreter;

type point = Unclaimed | Claimed | MultiClaimed

let getColumnNumbers = (rect: claim) => {
    let firstCol = rect.colStart;
    let rec buildColumns = (columns: list(int)) => {
        switch (firstCol == List.hd(columns)) {
            | true => columns;
            | false => buildColumns([List.hd(columns) - 1, ...columns]);
        }
    }

    buildColumns([rect.colStart + rect.width - 1]);
}

let getFirstRowPoints = (rect: claim): list((int, int)) => {
    getColumnNumbers(rect)
    |> List.map((colNumber => (colNumber, rect.rowStart)))
}

let buildPointsList = (rect: claim): list((int, int)) => {
    /* getFirstRowPoints(rect)
    |> getAllRowsFromFirstRow(rect); */
    [(1,2)];
}
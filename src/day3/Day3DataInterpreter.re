type claim = {
    id: int,
    startCol: int,
    startRow: int,
    height: int,
    width: int
}

let getId = (claimString: string): int => {
    let endOfId = String.index(claimString, ' ') - 1;
    String.sub(claimString, 1, endOfId)
    |> int_of_string
}

let getStartCol = (claimString: string): int => {
    let inchesFromLeftPosition = String.index(claimString, '@') + 2;
    let inchesFromLeftPositionEnd = String.index(claimString, ',');
    String.sub(claimString, inchesFromLeftPosition, inchesFromLeftPositionEnd - inchesFromLeftPosition)
    |> int_of_string
    |> (+)(1)
}

let getStartRow = (claimString: string): int => {
    let inchesFromTopPosition = String.index(claimString, ',') + 1;
    let inchesFromTopPositionEnd = String.index(claimString, ':');
    String.sub(claimString, inchesFromTopPosition, inchesFromTopPositionEnd - inchesFromTopPosition)
    |> int_of_string
    |> (+)(1)
}

let getHeight = (claimString: string): int => {
    String.sub(claimString, String.index(claimString, ':') + 2, String.length(claimString) - String.index(claimString, 'x') - 1)
    |> int_of_string;
}

let getWidth = (claimString: string): int => {
    String.sub(claimString, String.index(claimString, 'x') + 1, String.length(claimString) - String.index(claimString, 'x') - 1)
    |> int_of_string;
}

let buildClaim = (claimString: string): claim => { 
    {
        id: getId(claimString),
        startCol: getStartCol(claimString),
        startRow: getStartRow(claimString),
        height: getHeight(claimString),
        width: getWidth(claimString)
    };
};
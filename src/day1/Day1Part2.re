let data = Array.map(int_of_string, DataDay1.data)

let updateTotals = ( newTotal: int, totals: array(int)) => switch totals {
    | [||] => [|newTotal|];
    | _ => Array.concat([[|newTotal|] ,totals]) /*List.append([newTotal], totals)*/;
}

let incrementIndex = (arr: array(int), index: int) => {
    index >= Array.length(arr) - 1 ? 0 : index + 1;
};

let getNextTotal = (newValue: int, totals: array(int)) => switch totals {
    | [||] => newValue;
    | _ => totals[0] + newValue;
}

let contains = (value: 'a, arr: array('a)) => {
    let isContained = ref(false);
    Array.iter(el => {isContained := el == value}, arr);
    isContained^;
};

let isRepeat = (value: int, totals: array(int)) => switch totals {
    | [||] => false
    | _ => contains(value, totals);
};

let processDatum = ((data: array(int), idx: int, totals: array(int), success: bool)) => {
    let thisData = Array.get(data, idx);
    let nextTotal = getNextTotal(thisData, totals);
    let newTotals = updateTotals(nextTotal, totals);
    let newIdx = incrementIndex(data, idx);
    (data, newIdx, newTotals, isRepeat(nextTotal, totals)); 
}

let print_result = (tuple: (array(int), int, array(int), bool)): unit => {
    let (_, _, totals, _) = tuple;
    print_int(totals[0]);
}


let rec result = (tuple: (array(int), int, array(int), bool)) => {
    let nextTuple = processDatum(tuple)
    switch nextTuple {
        | (_, _, _, false) => result(nextTuple);
        | (_, _, _, true) => nextTuple;
    }
}

let init = (data, 0, [||], false);
/* print_result(result(init)) */


/*
- add val to last total [x] getNextTotal
- check totals list for new total [x] checkForValue
- add new total to list [x] updateTotals
- increment idx [x]
*/
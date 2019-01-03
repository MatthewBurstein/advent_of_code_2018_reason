let data = Day1Data.data;

let add = (x: int, y: int) => x + y;

let total = Array.map(int_of_string, data)
    |> Array.fold_left(add, 0);

print_int(total);
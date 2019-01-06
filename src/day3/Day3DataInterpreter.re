let getId = (claim: string): int => {
    let endOfId = String.index(claim, ' ') - 1;
    String.sub(claim, 1, endOfId)
    |> int_of_string
}
function maximize_profit(list_of_prices, starting_index, ending_index):
{
    IF length(list_of_prices)<2 THEN
        raise an Error and exit the program
    
    INITIALIZE maximum_profit to 0
    # base condition for recursion
    IF starting_index > ending_index THEN
        return maximum_profit
        
    FOR buying_counter in list_of_prices
        FOR selling_counter in list_of_prices
            UPDATE tentative_profit with the difference of the current two prices at hand
            RECURSIVELY call maximize_profit on the following two slices of the list:
            1. start: buy -1
            2. sell: end
            ADD the values obtained to the variable tentative_profit
            COMPUTE the maximum of maximum_profit and tentative profit
            & UPDATE the variable maximum_profit with the maximum computed.
        ENDFOR
    ENDFOR
    
    RETURN maximum_profit
}

function main():
{
    STORE the list of prices in LIST_OF_PRICES
    CALL maximize_profit() with argument LIST_OF_PRICES
    STORE the value returned by the function in variable PROFIT
    print PROFIT on the console. 
}
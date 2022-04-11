def max_min_fairness(available, requests):

    output = [0 for i in range(len(requests))]
    equal_contribution = available / len(requests)
    
    for i, j in enumerate(requests):
        
        if j <= equal_contribution:
            output[i] = j
            
        else:
            
            for h in range(i):
                available = available - output[h]
                
            equal_contribution = available / i
            
            for k in range(i):
                output[k+i] = equal_contribution
            break
            
    return output

requests = [2,4,6,7]
available = 16
test = max_min_fairness(available, requests)

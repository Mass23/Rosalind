NucleotideCounter <- function(sequence){
  acount = 0
  ccount = 0
  gcount = 0
  tcount = 0
  
  seq_split <- strsplit(sequence, "")[[1]]
  
  for (i in seq_split){
    print(i)
    
    if (i == 'A'){
      acount = acount + 1
    }
    
    else if (i == 'C'){
      ccount = ccount + 1
    }
    
    else if (i == 'G'){
      gcount = gcount + 1
    }
    
    else if (i == 'T'){
      tcount = tcount + 1
    }
  }
  return(list(acount, ccount, gcount, tcount))
}
NucleotideCounter(seq)

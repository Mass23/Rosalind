ReverseComplement <- function(sequence){
  rev_seq = ""
  
  seq_split <- strsplit(sequence, "")[[1]]
  
  for (i in length(seq_split):1){
    
    if (seq_split[i] == "A"){
      rev_seq = paste0(rev_seq, "T")
    }
    
    else if (seq_split[i] == "C"){
      rev_seq = paste0(rev_seq, "G")
    }
    
    else if (seq_split[i] == "G"){
      rev_seq = paste0(rev_seq, "C")
    }
    
    else if (seq_split[i] == "T"){
      rev_seq = paste0(rev_seq, "A")
    }
    
  }
  return(rev_seq)
}
ReverseComplement(seq)

HammingDistance <- function(sequence1, sequence2){
  
  seq_split1 <- strsplit(sequence1, "")[[1]]
  seq_split2 <- strsplit(sequence2, "")[[1]]
  match = 0
  mismatch = 0
  
  if (length(seq_split1) != length(seq_split2)){
    return(-1)
  }
  
  for (i in 1:length(seq_split1)){
    
    if (seq_split1[i] == seq_split2[i]){
      match = match + 1
    }
    
    else {
      mismatch = mismatch + 1
    }
    
  }
  return(mismatch)
}
HammingDistance(seq1,seq2)

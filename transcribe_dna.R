TranscribeSequence <- function(sequence){
  trans_seq = ""
  
  seq_split <- strsplit(sequence, "")[[1]]
  
  for (i in seq_split){
    
    if (i == 'T'){
      trans_seq = paste0(trans_seq, 'U')
    }
    
    else{
      trans_seq = paste0(trans_seq, i)
    }
    
  }
  return(trans_seq)
}
TranscribeSequence(seq)

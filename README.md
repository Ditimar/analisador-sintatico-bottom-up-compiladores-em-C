# analisador-sintatico-bottom-up-compiladores-em-C
Analisador sintatico estilo bottom-up, onde voce digita a expressao e ele diz se esta corretao ou nao!
gramtica
  S-> E
  E-> E+T
  E-> T
  T-> T*F
  F-> (E)
  F-> id
  

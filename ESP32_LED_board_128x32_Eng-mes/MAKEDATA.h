void makedata() {
  for (int yy = 0; yy < 36; yy++) {
    for (int xx = 0; xx < fst; xx++) {
      output[yy] += "K";
    }
  }
  for (int ii = 0; ii < msg.length(); ii++)
  {
    char ch = msg[ii];
    for (int yy = 0; yy < 5; yy++)
    {
      output[yy] += "KKKKK";
    }
    addchar(ch);
    for (int yy = 12; yy < 36; yy++)
    {
      output[yy] += "KKKKK";
    }
    for (int yy = 0; yy < 36; yy++)
    {
      for (int xx = 0; xx < dst; xx++) {
        output[yy] += "K";
      }
    }
  }
  for (int yy = 0; yy < 36; yy++) {
    for (int xx = 0; xx < lst; xx++) {
      output[yy] += "K";
    }
  }
}

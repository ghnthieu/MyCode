Program bai2;
uses crt;
var s:string;
procedure xuly;
var fi,fo:text;
    tong,i,t:integer;
begin
  assign(fi,'PWORD.INP');reset(fi);
  assign(fo,'PWORD.OUT');rewrite(fo);
  read(fi,s);
  tong:=0;
  for i:=1 to length(s) do
    if s[i] in['0'..'9'] then
      begin
        val(s[i],t);
        tong:=tong+t;
      end;
  write(fo,tong);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

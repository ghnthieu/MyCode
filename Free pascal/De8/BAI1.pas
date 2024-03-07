Program bai1;
var n:longint;
    k:byte;
procedure xuly;
var fi,fo:text;
    s:string;
    t,i,dem:byte;
    tong:integer;
begin
  assign(fi,'BAI1.INP');reset(fi);
  assign(fo,'BAI1.OUT');rewrite(fo);
  read(fi,n,k);
  str(n,s);
  tong:=0;
  dem:=length(s);
  for i:=1 to length(s) do
    begin
      val(s[i],t);
      if t mod 2=0 then
        tong:=tong+t;
    end;
  writeln(fo,dem);
  writeln(fo,tong);
  writeln(fo,s[k]);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

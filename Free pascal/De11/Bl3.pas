Program tinh;
var n:integer;
procedure xuly;
var fi,fo:text;
    dem:integer;
    tong:longint;
    a,b,c:byte;
begin
  assign(fi,'dulieu.inp');reset(fi);
  assign(fo,'ketqua.out');rewrite(fo);
  read(fi,n);
  dem:=0;
  tong:=0;
  for a:=1 to 9 do
    for b:=1 to 9 do
      for c:=1 to 9 do
        if a*b*c mod n=0 then
          begin
            inc(dem);
            tong:=tong+(a*100+b*10+c);
          end;
  if dem=0 then
    write(fo,'0 0')
  else
    write(fo,dem,' ',tong);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

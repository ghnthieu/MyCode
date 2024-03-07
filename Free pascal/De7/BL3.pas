Program bai3;
uses crt;
var n:byte;
    a:array[1..100] of integer;
procedure xuly;
var fi,fo1,fo2:text;
    i:byte;
    tong:integer;
begin
  assign(fi,'XE.INP');reset(fi);
  assign(fo1,'CAN.OUT');rewrite(fo1);
  assign(fo2,'HUY.OUT');rewrite(fo2);
  readln(fi,n);
  for i:=1 to n do
    read(fi,a[i]);
  tong:=0;
  for i:=1 to n do
    begin
      if a[i]>=20 then
        write(fo2,i,' ');
      tong:=tong+a[i];
    end;
  write(fo1,tong);
  close(fi);
  close(fo1);
  close(fo2);
end;
Begin
  xuly;
End.

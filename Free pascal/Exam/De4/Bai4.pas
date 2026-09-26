Program bai4;
uses crt;
type manga=array[1..100000] of integer;
     mangb=array[1..32767] of integer;
var a:manga;
    n:integer;
procedure xuly;
var i,tong,max:integer;
    b:mangb;
    fi,fo:text;
begin
  assign(fi,'Dayso.inp');reset(fi);
  assign(fo,'Dayso.out');rewrite(fo);
  readln(fi,n);
  for i:=1 to n do
    read(fi,a[i]);
  tong:=0;
  max:=a[1];
  for i:=1 to n do
    tong:=tong+a[i];
  writeln(fo,tong);
  for i:=2 to n do
    if max<a[i] then
      max:=a[i];
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    inc(b[a[i]]);
  for i:=1 to max do
    if b[i]<>0 then
      writeln(fo,i,':',b[i]);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

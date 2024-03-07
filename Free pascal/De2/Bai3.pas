Program bai3;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
    k:integer;
procedure nhap(var a:mang; var n:byte; var k:integer);
var i:byte;
begin
  repeat
    readln(n);
  until (n>0) and (n<=100);
  for i:=1 to n do
    read(a[i]);
  readln(k);
end;
procedure doicho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure xuly(a:mang; n:byte; k:integer);
var i,j:byte;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        doicho(a[i],a[j]);
  for i:=1 to n do
    write(a[i],' ');
  writeln;
  i:=1;
  while (a[i]>k) and (i<=n) do
    inc(i);
  for j:=n downto i do
    a[j+1]:=a[j];
  a[i]:=k;
  inc(n);
  for i:=1 to n do
    write(a[i],' ');
end;
Begin
  clrscr;
  nhap(a,n,k);
  xuly(a,n,k);
  readln
End.

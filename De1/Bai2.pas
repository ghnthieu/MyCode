Program bai2;
uses crt;
type mang=array[1..100] of integer;
var n:byte;
    a:mang;
    k:integer;
procedure nhap(var a:mang; var n:byte; var k:integer);
var i:byte;
begin
  repeat
    write('N=');readln(n);
  until (n<=100);
  write('K=');readln(k);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
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
    tong:longint;
begin
  tong:=0;
  for i:=1 to n do
    if a[i] mod 2=0 then
      tong:=tong+a[i];
  writeln('-Tong cac so chan: ',tong);
  tong:=0;
  for i:=1 to n do
    if a[i]=k then
      tong:=tong+a[i];
  writeln('-Tong cac phan tu bang k: ',tong);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        doicho(a[i],a[j]);
  write('-Day so sau khi sap xep giam dan: ');
  for i:=1 to n do
    begin
      write(a[i]);
      if i<n then
        write(',');
    end;
end;
Begin
  clrscr;
  nhap(a,n,k);
  xuly(a,n,k);
  readln
End.

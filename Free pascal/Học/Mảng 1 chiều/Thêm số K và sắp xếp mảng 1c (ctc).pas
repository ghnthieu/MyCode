Program chen_mang;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
    k:integer;
procedure nhap(var a:mang; var n:byte; var k:integer);
var i:byte;
begin
  write('Nhap so phan tu: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
  write('Nhap so nguyen K: ');readln(k);
end;
procedure doi_cho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure sx_giam(a:mang;n:byte;k:integer);
var i,j:integer;
begin
  writeln('Sap xep theo thu tu giam dan khi da them K la: ');
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        doi_cho(a[i],a[j]);
  i:=1;
  while (a[i]>k) and (i<=n) do
    inc(i);
  for j:=n downto i do
    a[j+1]:=a[j];
  a[i]:=k;
  inc(n);
  for i:=1 to n do
    write(a[i],' ');
  writeln;
  writeln('Sap xep theo thu tu tang dan khi da them K la: ');
end;
procedure sx_tang(a:mang;n:byte;k:integer);
var i,j:integer;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        doi_cho(a[i],a[j]);
  i:=1;
  while (a[i]<k) and (i<=n) do
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
  sx_giam(a,n,k);
  sx_tang(a,n,k);
  readln
End.








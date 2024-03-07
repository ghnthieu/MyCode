Program bai1;
uses crt;
type mang=array [1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  repeat
    write('Nhap so nguyen N: ');readln(n);
  until (n>0) and (n<100);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure doi_cho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure xuly(a:mang; n:byte);
var i,j:byte;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        doi_cho(a[i],a[j]);
  write('Day theo tu tu tang dan la: ');
  for i:=1 to n do
    write(a[i],' ');
end;
Begin
  clrscr;
  nhap(a,n);
  xuly(a,n);
  readln
End.
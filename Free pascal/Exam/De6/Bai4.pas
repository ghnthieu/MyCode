Program bai4;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap n: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure xuly(a:mang; n:byte);
var i,t:byte;
    max:integer;
begin
  max:=a[1];
  t:=0;
  for i:=2 to n do
    if max<a[i] then
      begin
        max:=a[i];
        t:=i;
      end;
  write('So lon nhat cua day la: ',max,' vi tri ',t);
end;
Begin
  clrscr;
  nhap(a,n);
  xuly(a,n);
  readln
End.

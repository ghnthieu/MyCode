Program mang1c;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap do dai mang: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure in_sln(a:mang; n:byte);
var max,min:integer;
    i:byte;
begin
  max:=a[1];
  min:=a[1];
  for i:=2 to n do
    begin
      if max<a[i] then
        max:=a[i];
      if min>a[i] then
        min:=a[i];
    end;
  writeln('Gia tri lon nhat trong mang la: ',max);
  writeln('Gia tri nho nhat trong mang la: ',min);
end;

Begin
  clrscr;
  nhap(a,n);
  in_sln(a,n);
  readln
End.
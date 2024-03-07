Program Dequy_fibo;
uses crt;
var n:byte;
procedure nhap(var n:byte);
begin
  write('Nhap n: ');readln(n);
end;
function fibo(n:byte):qword;
begin
  if ((n=1) or (n=2)) then
    fibo:=1
  else
    fibo:=fibo(n-1)+fibo(n-2);
end;
procedure xuly(n:byte);
begin
  write(fibo(n));
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
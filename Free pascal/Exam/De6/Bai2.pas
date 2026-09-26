Program bai2;
uses crt;
var a,b,c:real;
procedure nhap(var a,b,c:real);
begin
  write('Nhap a: ');readln(a);
  write('Nhap b: ');readln(b);
  write('Nhap c: ');readln(c);
end;
procedure xuly(a,b,c:real);
begin
  if (a>=b+c) or (b>=a+c) or (c>=a+b) then
    write('x,y,z Khong phai la do dai 3 canh cua mot tam giac')
  else
    write('x,y,z La do dai 3 canh cua mot tam giac');
end;
Begin
  clrscr;
  nhap(a,b,c);
  xuly(a,b,c);
  readln
End.

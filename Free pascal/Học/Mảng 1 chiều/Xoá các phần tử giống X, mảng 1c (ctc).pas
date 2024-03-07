Program xoa_mang;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
    x:integer;
procedure nhap(var a:mang; var n:byte; var x:integer);
var i:byte;
begin
  write('Nhap so phan tu: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
  write('Nhap so nguyen X: ');readln(x);
end;
procedure xoa_pt(a:mang;n:byte;x:integer);
var i,tam,j,k:integer;
begin
  tam:=n;
  i:=1;
  while i<=n do
    if a[i]=x then
      begin
        for j:=i to n-1 do
          a[j]:=a[j+1];
        dec(n);
      end
    else
      inc(i);
  if n=0 then
    write('Phan tu da bi xoa het')
  else
    if tam<>n then
      begin
        write('Day so sau khi xoa cac phan tu giong X la: ');
        for i:=1 to n do
          write(a[i],' ');
      end
    else
      write('Day so khong bi xoa phan tu nao ca');
end;

Begin
  clrscr;
  nhap(a,n,x);
  xoa_pt(a,n,x);
  readln
End.

Program mang_2c;
uses crt;
type mang=array[1..10,1..10] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i,j:byte;
begin
  write('Nhap cap ma tran: ');readln(n);
  for i:=1 to n do
    for j:=1 to n do
      begin
        write('a[',i,',',j,']=');readln(a[i,j]);
      end;
end;
procedure in_ra(a:mang; n:byte);
var i,j:byte;
begin
  for i:=1 to n do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
      writeln;
    end;
end;
procedure tt_dc(a:mang; n:byte);
var i:byte;
    tong:integer;
begin
  tong:=0;
  for i:=1 to n do
    tong:=tong+a[i,i];
  writeln('Tong duong cheo chinh la: ',tong);
end;
function kt_dx(a:mang; n:byte):boolean;
var i,j:byte;
    ok:boolean;
begin
  ok:=true;
  for i:=1 to n do
    for j:=1 to n do
      if (a[i,j]<>a[j,i]) then
        begin
          ok:=false;
          exit;
        end;
  kt_dx:=ok;
end;
procedure in_dx(a:mang; n:byte);
begin
  if kt_dx(a,n) then
    write('Mang doi xung')
  else
    write('Mang khong doi xung');
end;
Begin
  clrscr;
  nhap(a,n);
  in_ra(a,n);
  tt_dc(a,n);
  in_dx(a,n);
  readln
End.
Program Fibonaci;
uses crt;
var n:integer;
procedure nhap(var n:integer);
begin
  readln(n);
end;
procedure xuly(n:integer);
var f:array[0..93] of qword;
    i,j:byte;
    tong:qword;
begin
  f[0]:=0;
  f[1]:=1;
  i:=1;
  tong:=1;
  repeat
    inc(i);
    f[i]:=f[i-1]+f[i-2];
    tong:=tong+f[i];
  until (tong>=n);
  if (tong=n) then
    for j:=1 to i do
      begin
        write(f[j]);
        if (j<i) then
          write('+');
      end
  else
    write('KHONG THE PHAN TICH');
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.



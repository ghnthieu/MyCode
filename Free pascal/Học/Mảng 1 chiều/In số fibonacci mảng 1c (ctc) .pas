Program day_fibonacci;
uses crt;
type mang=array[1..100] of qword;
     sn=byte;
var n:sn;
    F:mang;
procedure nhap(var n:sn);
begin
  repeat
    write('nhap so nguyen duong N: ');readln(n);
  until (n>=1) and (n<=90);
end;
procedure fbc(var f:mang; n:sn);
var i:sn;
begin
  F[1]:=1;
  F[2]:=1;
  for i:=3 to n do
    F[i]:=F[i-1]+F[i-2];
end;
procedure in_fbc(f:mang; n:sn);
var i:sn;
begin
  for i:=1 to n do
    begin
      write(F[i]);
      if i<n then
        write(',');
    end;
end;
Begin
  clrscr;
  nhap(n);
  fbc(F,n);
  in_fbc(F,n);
  readln
End.
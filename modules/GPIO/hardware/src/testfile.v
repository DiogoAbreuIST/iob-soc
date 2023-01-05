module test_module
    (
    input clk,
    input [31:0] DATA_IN,
    output reg[7:0] RESULT
    );

`IOB_VAR(a,8)
`IOB_VAR(b,8)
`IOB_VAR(c,8)
`IOB_VAR(d,8)
`IOB_VAR(e,8)
`IOB_VAR(f,8)
`IOB_VAR(out,8)

`IOB_COMB begin
    
    a = DATA_IN[31:24];
    b = DATA_IN[23:16];
    c = DATA_IN[15:8];
    d = DATA_IN[7:0];
    e = `IOB_MAX(a,b);
    f = `IOB_MAX(c,d);
    out = `IOB_MAX(e,f);

end


assign RESULT = out;

endmodule

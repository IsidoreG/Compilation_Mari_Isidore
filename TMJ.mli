(** This is the same abstract syntax tree as in [LMJ.mli] but without position informations.
    After typechecking, we don't need to give feedbacks to the user. *)

type identifier = string

type expression = { raw_expression : raw_expression; typ : typ }

and raw_expression =
  | EConst of constant
  | EGetVar of identifier
  | EUnOp of unop * expression
  | EBinOp of binop * expression * expression
  | EMethodCall of expression * identifier * expression list
  | EArrayGet of expression * expression
  | EArrayAlloc of expression
  | EArrayLength of expression
  | EThis
  | EObjectAlloc of identifier

and constant = LMJ.constant =
  | ConstBool of bool
  | ConstInt of int32

and binop = LMJ.binop =
  | OpAdd
  | OpSub
  | OpMul
  | OpDiv
  | OpLt
  | OpGt
  | OpAnd
  | OpOr
  | OpBitAnd
  | OpBitOr
  | OpXor
  | OpEquals

and unop = LMJ.unop = UOpNot

and instruction =
  | IBlock of instruction list
  | IIfWithoutElse of expression * instruction
  | IIf of expression * instruction * instruction
  | IWhile of expression * instruction
  | IDoWhile of instruction * expression 
  | IFor of identifier * expression * expression * identifier * expression * instruction
  | ISyso of expression
  | ISetVar of identifier * typ * expression
  | IArraySet of identifier * expression * expression
  | IBreak
  | IReturn of expression

and typ =
  | TypInt
  | TypBool
  | TypIntArray
  | Typ of identifier

and metho = {
    formals: (identifier * typ) list;
    result: typ;
    locals: (identifier * typ) list;
    body: instruction list;
  }

and clas = {
    extends: identifier option;
    attributes: (identifier * typ) list;
    methods: (identifier * metho) list
  }

and program = {
    name: identifier;
    defs: (identifier * clas) list;
    main_args: identifier;
    main: instruction list
  }

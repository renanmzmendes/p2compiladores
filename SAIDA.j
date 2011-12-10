.class public MainProgram
.super java/lang/Object

.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method


.method public static main([Ljava/lang/String;)V
	.limit locals 40
	.limit stack 30
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 0
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 1
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 2
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 3
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 4
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 5
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 6
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 7
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 8
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 9
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 10
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 11
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 12
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 13
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 14
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 15
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 16
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 17
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 18
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 19
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 20
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 21
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 22
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 23
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 24
	new java/util/Stack
	dup
	invokespecial java/util/Stack/<init>()V
	astore 25
	aload 0
	bipush 7
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
	pop
	aload 0
	bipush 7
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
	pop
	aload 0
	bipush 9
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
	pop
	loop_0:
	aload 0
	invokevirtual java/util/Stack.empty()Z
	ifne fimloop_0
	aload 1
	aload 0
	invokevirtual java/util/Stack/pop()Ljava/lang/Object;
	invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
	pop
	loop_1:
	aload 0
	invokevirtual java/util/Stack.empty()Z
	ifne fimloop_1
	aload 2
	aload 0
	invokevirtual java/util/Stack/pop()Ljava/lang/Object;
	invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
	pop
	 goto loop_1
	fimloop_1:
	 goto loop_0
	fimloop_0:
return
.end method

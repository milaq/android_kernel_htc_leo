#ifndef _XT_SOCKET_H
#define _XT_SOCKET_H

enum {
	XT_SOCKET_TRANSPARENT = 1 << 0,
};

struct xt_socket_mtinfo1 {
	__u8 flags;
};

<<<<<<< HEAD
void xt_socket_put_sk(struct sock *sk);
struct sock *xt_socket_get4_sk(const struct sk_buff *skb,
			       struct xt_action_param *par);
struct sock *xt_socket_get6_sk(const struct sk_buff *skb,
			       struct xt_action_param *par);

=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#endif /* _XT_SOCKET_H */

/* crypto/sm2/sm2_err.c */
/* ====================================================================
 * Copyright (c) 2015 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 */


#include <stdio.h>
#include <openssl/err.h>
#include "sm2.h"

#ifndef OPENSSL_NO_ERR

#define ERR_FUNC(func) ERR_PACK(ERR_LIB_ECIES,func,0)
#define ERR_REASON(reason) ERR_PACK(ERR_LIB_ECIES,0,reason)


static ERR_STRING_DATA SM2_str_functs[] = {
        {ERR_FUNC(SM2_F_SM2_SET_ID),			"SM2_SET_ID"},
        {ERR_FUNC(SM2_F_SM2_GET_ID),			"SM2_F_SM2_GET_ID"},
        {ERR_FUNC(SM2_F_SM2_COMPUTE_ID_DIGEST),		"SM2_compute_id_digest"},
        {ERR_FUNC(SM2_F_SM2_CIPHERTEXT_VALUE_SIZE),	"SM2_CIPHERTEXT_VALUE_size"},
        {ERR_FUNC(SM2_F_SM2_CIPHERTEXT_VALUE_FREE),	"SM2_CIPHERTEXT_VALUE_free"},
        {ERR_FUNC(SM2_F_SM2_CIPHERTEXT_VALUE_ENCODE),	"SM2_CIPHERTEXT_VALUE_encode"},
        {ERR_FUNC(SM2_F_SM2_CIPHERTEXT_VALUE_DECODE),	"SM2_CIPHERTEXT_VALUE_decode"},
        {ERR_FUNC(SM2_F_SM2_CIPHERTEXT_VALUE_PRINT),	"SM2_CIPHERTEXT_VALUE_print"},
        {ERR_FUNC(SM2_F_SM2_DO_ENCRYPT),		"SM2_do_encrypt"},
        {ERR_FUNC(SM2_F_SM2_DO_DECRYPT),		"SM2_do_decrypt"},
        {ERR_FUNC(SM2_F_SM2_ENCRYPT),			"SM2_encrypt"},
        {ERR_FUNC(SM2_F_SM2_DECRYPT),			"SM2_decrypt"},
        {ERR_FUNC(SM2_F_SM2_SIGNATURE_SIZE),		"SM2_signature_size"},
        {ERR_FUNC(SM2_F_SM2_SIGN_SETUP),		"SM2_sign_setup"},
        {ERR_FUNC(SM2_F_SM2_DO_SIGN_EX),		"SM2_do_sign_ex"},
        {ERR_FUNC(SM2_F_SM2_DO_SIGN),			"SM2_do_sign"},
        {ERR_FUNC(SM2_F_SM2_DO_VERIFY),			"SM2_do_verify"},
        {ERR_FUNC(SM2_F_SM2_SIGN_EX),			"SM2_sign_ex"},
        {ERR_FUNC(SM2_F_SM2_SIGN),			"SM2_sign"},
        {ERR_FUNC(SM2_F_SM2_VERIFY),			"SM2_verify"},
        {ERR_FUNC(SM2_F_SM2_KAP_CTX_INIT),		"SM2_KAP_CTX_init"},
        {ERR_FUNC(SM2_F_SM2_KAP_CTX_CLEANUP),		"SM2_KAP_CTX_cleanup"},
        {ERR_FUNC(SM2_F_SM2_KAP_PREPARE),		"SM2_KAP_prepare"},
        {ERR_FUNC(SM2_F_SM2_KAP_COMPUTE_KEY),		"SM2_KAP_compute_key"},
        {ERR_FUNC(SM2_F_SM2_KAP_FINAL_CHECK),		"SM2_KAP_final_check"},
        {0,NULL}
};

static ERR_STRING_DATA SM2_str_reasons[] = {
        {ERR_REASON(SM2_R_BAD_DATA),			"bad data"},
        {ERR_REASON(SM2_R_UNKNOWN_CIPHER_TYPE),		"unknown cipher type"},
        {ERR_REASON(SM2_R_ENCRYPT_FAILED),		"encrypt failed"},
        {ERR_REASON(SM2_R_DECRYPT_FAILED),		"decrypt failed"},
        {ERR_REASON(SM2_R_UNKNOWN_MAC_TYPE),		"unknown MAC type"},
        {ERR_REASON(SM2_R_GEN_MAC_FAILED),		"MAC generation failed"},
        {ERR_REASON(SM2_R_VERIFY_MAC_FAILED),		"MAC verification failed"},
        {ERR_REASON(SM2_R_ECDH_FAILED),			"ECDH failed"},
        {ERR_REASON(SM2_R_BUFFER_TOO_SMALL),		"buffer too small"},
        {ERR_REASON(SM2_R_SM2_KAP_NOT_INITED),		"KAP not inited"},
        {ERR_REASON(SM2_R_RANDOM_NUMBER_GENERATION_FAILED), "random number generation failed"},
        {0,NULL}
};

#endif

void ERR_load_SM2_strings(void)
{
#ifndef OPENSSL_NO_ERR

        if (ERR_func_error_string(SM2_str_functs[0].error) == NULL) {
                ERR_load_strings(0,SM2_str_functs);
                ERR_load_strings(0,SM2_str_reasons);
        }
#endif
}

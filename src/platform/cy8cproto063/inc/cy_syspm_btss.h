/***************************************************************************//**
* \file cy_syspm_btss.h
* \version 5.95
*
* Provides the API declarations of the BTSS driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2021 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/**
* \addtogroup group_syspm_btss BTSS Host API(Bluetooth Sub System Host API)
* \{
* BTSS PDL Driver helps in controlling the BTSS from the MCU side.
*
* For more information on the BTSS , refer to
* the technical reference manual (TRM).
*
* \section group_syspm_btss_MISRA MISRA-C Compliance
* The BTSS driver does not have any specific deviations.
*
* \section group_syspm_btss_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_syspm_btss_macros Macros
* \defgroup group_syspm_btss_functions Functions
* \defgroup group_syspm_btss_data_structures Data Structures
* \defgroup group_syspm_btss_enums           General Enumerated Types
* \{
*   \defgroup group_syspm_btss_returns         Function return values
* \}
*/

#ifndef CY_BTSS_H
#define CY_BTSS_H

#include "cy_device.h"

#if defined (CY_IP_MXS40BLE52SS)

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"
#include "cy_device_headers.h"
#include "cy_sysclk.h"
#include "cy_syspm_pdcm.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* \addtogroup group_syspm_btss_macros
* \{
*/

/** Driver major version */
#define CY_BTSS_DRV_VERSION_MAJOR       5
/** Driver minor version */
#define CY_BTSS_DRV_VERSION_MINOR       91
/** Timeout for SL CTL3 register wait in micro seconds */
#define CY_BTSS_SL_CTL3_WAIT_DELAY_US   500000UL
/** \} group_syspm_btss_macros */

/**
* \addtogroup group_syspm_btss_returns
* \{
*/
/** Defines general-purpose function return values */
typedef enum
{
    CY_BTSS_SUCCESS           = CY_SYSPM_SUCCESS, /**< Command completed with no errors */
    CY_BTSS_BAD_PARAM         = CY_SYSPM_BAD_PARAM, /**< Invalid function input parameter */
    CY_BTSS_TIMEOUT           = CY_SYSPM_TIMEOUT, /**< Timeout occurred */
    CY_BTSS_INVALID_STATE     = CY_SYSPM_INVALID_STATE, /**< BTSS is in an invalid state */
} cy_en_btss_status_t;
/** \} group_syspm_btss_returns */

/**
* \addtogroup group_syspm_btss_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_BTSS_GetXtalOscFreq
****************************************************************************//**
*
* Gets the Crystal Oscillator Frequency(Hz) generated by Radio Hard IP
*
* \return Frequency(Hz) of Crystal Oscillator generated by Radio Hard IP
*
*******************************************************************************/
uint32_t Cy_BTSS_GetXtalOscFreq(void);

/*******************************************************************************
* Function Name: Cy_BTSS_PowerDep
****************************************************************************//**
*
* Enable/Disable the Power dependency of BTSS on CPUSS.
* If enabled, BTSS will wake up and will be ON as long as CPUSS is ON.
*
* \param enable TRUE-Enable, FASLE-Disable
*
* \return \ref cy_en_btss_status_t
*
* \note
* This API needs to be used to wake and keep the BTSS ON , while CPUSS is ON.
*
*******************************************************************************/
cy_en_btss_status_t Cy_BTSS_PowerDep(bool enable);

/*******************************************************************************
* Function Name: Cy_BTSS_CPUSSPowerDep
****************************************************************************//**
*
* Enable/Disable the Power dependency of CPUSS on BTSS.
* If enabled, CPUSS will be ON as long as BTSS is ON.
*
* \param enable TRUE-Enable, FASLE-Disable
*
* \return \ref cy_en_btss_status_t
*
* \note
* This API needs to be used if we need to keep the CPUSS ON , while BTSS is ON.
*
*******************************************************************************/
cy_en_btss_status_t Cy_BTSS_CPUSSPowerDep(bool enable);

/*******************************************************************************
* Function Name: Cy_BTSS_AssertReset
****************************************************************************//**
*
* Asserts/De-Asserts Reset of BTSS IP.
*
* \param assertEn TRUE-Enable, FALSE-Disable
*
*******************************************************************************/
void Cy_BTSS_AssertReset(bool assertEn);

/*******************************************************************************
* Function Name: Cy_BTSS_IsResetAsserted
****************************************************************************//**
*
* Checks if BTSS IP Reset is Asserted or not.
*
* \return TRUE- if Assert Enabled, FALSE- if Assert Disabled.
*
*******************************************************************************/
bool Cy_BTSS_IsResetAsserted(void);

/** \} group_syspm_btss_functions */


#ifdef __cplusplus
}
#endif

#endif /* CY_IP_MXS40BLE52SS */

#endif /* CY_BTSS_H */

/** \} group_syspm_btss */

/* [] END OF FILE */
